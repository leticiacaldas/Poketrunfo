# Nome do executável
TARGET = poketrunfo

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -g -Wall

# Arquivos fonte
SRCS = main.c jogo.c busca.c pokedex.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Regra para criar arquivos objeto
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e do executável
clean:
    rm -f $(OBJS) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
    ./$(TARGET)
