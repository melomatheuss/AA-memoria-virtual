# AA-memoria-virtual
Este projeto é uma aplicação em C que realiza a leitura de um arquivo de texto (biblia.txt) e realiza algumas operações de manipulação e verificação de dados.

# Funcionalidades

    Abrir e Ler Arquivo: O programa abre o arquivo biblia.txt para leitura e obtém o tamanho total do arquivo em bytes.
    Cálculo de Páginas Virtuais: Calcula quantas páginas virtuais (de 4096 bytes cada) seriam necessárias para armazenar o arquivo completo.
    Leitura do Conteúdo na Memória: Lê o conteúdo do arquivo para a memória alocada dinamicamente.
    Impressão dos Últimos 10 Bytes: Imprime os últimos 10 bytes do arquivo em formato hexadecimal.
    Verificação do Conteúdo Final: Verifica se os últimos 6 bytes do arquivo contêm a string "Amen.\n".

# Pré-requisitos

Certifique-se de ter um compilador C instalado, como o GCC, e que o arquivo biblia.txt esteja disponível no mesmo diretório que o programa.
Instalação

Clone o repositório:

  

    git clone https://github.com/melomatheuss/AA-memoria-virtual.git

Navegue até a pasta do projeto e compile o programa:



    gcc -o memoriaVirtual memoriaVirtual.c

#  Execução

Após a compilação, execute o programa com o seguinte comando:



    ./memoriaVirtual

Saída Esperada

O programa exibirá:

    O tamanho total do arquivo em bytes.
    Os últimos 10 bytes do arquivo em formato hexadecimal.
    Uma mensagem indicando se os últimos 6 bytes correspondem a "Amen.\n".

Exemplo de saída:

python

O arquivo lido possui 1234567 bytes.
Últimos 10 bytes do arquivo:
0x41 0x6d 0x65 0x6e 0x2e 0x0a ...
Os últimos 6 bytes do arquivo são 'Amen.\n'?
Sim, os últimos 6 bytes são 'Amen.'

Tecnologias Utilizadas

    C: Linguagem de programação utilizada para desenvolvimento do programa.
    GCC: Compilador utilizado para compilar o código-fonte.

O código está estruturado da seguinte forma:

    Definição de Constantes:
        #define TAMANHO_PAGINA 4096: Define o tamanho de uma página de memória virtual.

    Abertura e Leitura do Arquivo:
        Utiliza fopen para abrir o arquivo e fseek/ftell para determinar o tamanho do arquivo.

    Cálculo de Páginas Virtuais:
        Calcula o número de páginas virtuais necessárias para armazenar o arquivo, considerando o tamanho padrão de 4096 bytes por página.

    Alocação Dinâmica e Leitura na Memória:
        Utiliza malloc para alocar memória e fread para ler o conteúdo do arquivo na memória.

    Manipulação e Verificação do Conteúdo:
        Imprime os últimos 10 bytes do arquivo e verifica se os últimos 6 bytes contêm "Amen.\n".

    Liberação de Recursos:
        Fecha o arquivo com fclose e libera a memória alocada com free.
