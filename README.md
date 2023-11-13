# Projeto "Touhou Clone"

## Configuração

### Windows

Para usar o \*Visual Studio 2022, rode o `GenerateVSFiles.bat`
Para usar o \*MinGW, rode o `GenerateMinGWFiles.bat`

\* Caso possua outra edição, edite o arquivo GenerateVSFiles.bat com a edição desejada (<https://premake.github.io/docs/Using-Premake/>):

### Linux

Para gerar os arquivos Makefile para o GCC, execute no terminal:

```sh
./premake5/premake5 gmake2
```

### Rodar

Para rodar o Programa, navegue na pasta criada em `build/{ Configuração }/{ Plataforma }/bin` e rode o executável.
