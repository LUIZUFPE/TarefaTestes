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

````
````
