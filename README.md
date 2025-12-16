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
code programa.c
```
Observação: o arquivo programa.c é apenas um exemplo. Qualquer nome de arquivo e qualquer lógica de código podem ser utilizados, conforme o interesse do usuário.

### 6.3. Compilação do programa
Após criar o arquivo, utilize o compilador instrumentado do AFL++ para gerar o binário:

```bash
afl-clang-fast programa.c -o programa
```
Esse comando gera um executável instrumentado, pronto para ser utilizado posteriormente com o afl-fuzz.

### 6.3.1 Garantindo a disponibilidade do AFL++
Caso necessário, é possível garantir que as ferramentas do AFL++ estejam disponíveis no sistema por meio do gerenciador de pacotes do Ubuntu:
```bash
Copiar código
sudo apt install afl++
```
Após a instalação, ferramentas como afl-fuzz, afl-clang-fast e afl-cc estarão disponíveis globalmente no sistema.


