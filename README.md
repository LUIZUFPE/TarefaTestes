# TarefaTestes


Este tutorial descreve o processo de instalação e execução básica do **AFL++ (American Fuzzy Lop Plus Plus)** em um ambiente **Linux (Ubuntu) no WSL**, utilizando o terminal.

---

## 1. Atualização do sistema e instalação de dependências

Antes de instalar o AFL++, é necessário atualizar a lista de pacotes do sistema e instalar as dependências essenciais para compilação.

```bash
sudo apt update
sudo apt install -y git build-essential clang llvm cmake
````

Esses pacotes são necessários porque:

* **git**: permite clonar o repositório do AFL++
* **build-essential**: fornece compiladores e ferramentas básicas (gcc, make)
* **clang** e **llvm**: compiladores recomendados para instrumentação
* **cmake**: utilizado no processo de build

---

## 2. Clonando o repositório do AFL++

Após instalar as dependências, o próximo passo é clonar o repositório oficial do AFL++.

```bash
git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
```

Esse comando baixa o código-fonte e acessa o diretório do projeto.

---

## 3. Compilação do AFL++

Com o repositório clonado, é necessário compilar o AFL++ a partir do código-fonte.

```bash
make distrib
```

Esse comando compila todas as ferramentas do AFL++ e prepara o ambiente para instalação.

---

## 4. Instalação do AFL++

Após a compilação bem-sucedida, execute o comando abaixo para instalar o AFL++ no sistema:

```bash
sudo make install
```

Durante esse processo, o sistema solicitará a senha de administrador (`sudo`).
Ao final da instalação, os binários como `afl-fuzz`, `afl-cc`, `afl-clang-fast` e outras ferramentas estarão disponíveis globalmente no sistema.

---

## 5. Verificação da instalação (opcional)

Para confirmar se o AFL++ foi instalado corretamente, execute:

```bash
afl-fuzz -h
```

Se a ajuda do AFL++ for exibida, a instalação foi concluída com sucesso.


## 6. Compilação de um programa C com AFL++

Após a instalação do AFL++, é possível compilar programas em C utilizando o compilador instrumentado `afl-clang-fast`, que adiciona automaticamente a instrumentação necessária para o fuzzing.

### 6.1. Criação do diretório de testes

Primeiro, crie um diretório para organizar os arquivos do projeto.  
O nome do diretório é livre; neste tutorial será utilizado o diretório `afl-teste` apenas como exemplo:

```bash
mkdir afl-teste
cd afl-teste
```

### 6.2. Criação do arquivo de teste
O nome do arquivo pode ser escolhido livremente, assim como o seu conteúdo, de acordo com o programa que se deseja testar com fuzzing.
Para fins de organização, todos os arquivos relacionados ao teste ficam dentro do diretório afl-teste.

Exemplo de criação de um arquivo em C:

```bash
code programaTarefa.c
```
Observação: o arquivo programaTarefa.c é apenas um exemplo. Qualquer nome de arquivo e qualquer lógica de código podem ser utilizados, conforme o interesse do usuário.

### 6.3. Compilação do programa
Após criar o arquivo, utilize o compilador instrumentado do AFL++ para gerar o binário:

```bash
afl-clang-fast -o programaTarefa programaTarefa.c
```
Esse comando gera um executável instrumentado, pronto para ser utilizado posteriormente com o afl-fuzz.

### 6.3.1 Garantindo a disponibilidade do AFL++
Caso necessário, é possível garantir que as ferramentas do AFL++ estejam disponíveis no sistema por meio do gerenciador de pacotes do Ubuntu:
```bash
sudo apt install afl++
```
Após a instalação, ferramentas como afl-fuzz, afl-clang-fast e afl-cc estarão disponíveis globalmente no sistema.

## 7. Preparação dos seeds (casos de entrada iniciais)

Antes de executar o `afl-fuzz`, é necessário fornecer um conjunto inicial de entradas, chamadas de **seeds**.  
Esses arquivos servem como ponto de partida para que o fuzzer gere novas variações de teste.

### 7.1. Criação do diretório de seeds

Dentro do diretório do projeto (`afl-teste`), crie o diretório de seeds:

```bash
mkdir seeds_programaTarefa
```
### 7.2. Criação de um seed inicial
O nome do arquivo e o conteúdo do seed são livres e devem estar de acordo com o formato de entrada esperado pelo programa testado.
Exemplo de criação de um seed simples:

```bash
echo "AA" > seeds_programaTarefa/seed1.txt
```
Esse arquivo será utilizado pelo AFL++ como entrada inicial durante o fuzzing.

## 8. Configuração para ignorar crashes ausentes (dont-care-crashes)

Em alguns cenários de teste, especialmente em fases iniciais de fuzzing, é aceitável não se preocupar com a ausência de crashes esperados.  
Para esse comportamento, é possível configurar uma variável de ambiente antes de executar o `afl-fuzz`.

### 8.1. Definição da variável de ambiente

Execute o comando abaixo no terminal:

```bash
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1
```
Essa variável informa ao AFL++ que a ausência de crashes não deve interromper ou invalidar a execução do fuzzing.

## 9. Execução do AFL++ com a configuração aplicada
Após definir a variável de ambiente, execute o fuzzing normalmente:

```bash
afl-fuzz -i seeds_programaTarefa -o out_programaTarefa ./programaTarefa @@
```
## 10. Opção extra: exploração dos arquivos de crash

Caso o usuário queira explorar com mais detalhes os arquivos gerados na saída de crashes, é possível utilizar um programa específico para análise de comportamento diante de falhas, como o arquivo `crash.c`.

### 10.1. Disponibilidade do arquivo `crash.c`

O arquivo `crash.c` está disponível neste repositório e pode ser utilizado diretamente para fins de estudo e experimentação.  
Seu objetivo é provocar falhas de forma controlada, permitindo observar o comportamento do AFL++ diante de situações de crash.

### 10.2. Compilação do arquivo `crash.c`

Após acessar o diretório do projeto, compile o arquivo utilizando o compilador instrumentado do AFL++:

```bash
afl-clang-fast crash.c -o crash
```
### 10.3. Execução com AFL++
Após a compilação, utilize os mesmos comandos de execução já apresentados anteriormente no tutorial, incluindo:

o diretório de seeds;

o diretório de saída (out);

a variável de ambiente de dont care about missing crashes.

Em seguida, execute o fuzzing normalmente, substituindo apenas o binário alvo pelo executável crash.
Essa execução permitirá observar o comportamento da ferramenta diante de situações de falha e analisar os arquivos gerados no diretório de saída.
```bash
# seed
echo teste > seeds/input1.txt

# variável de ambiente (dont care about missing crashes)
export AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1

# execução do AFL++
afl-fuzz -i seeds -o out -- ./crash @@
```
