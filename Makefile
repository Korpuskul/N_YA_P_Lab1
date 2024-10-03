# Компилятор
CC = g++

# Флаги компиляции
CFLAGS = -Wall -g

# Исходные файлы
SOURCES = func.cpp Lab1.cpp

# Имя исполняемого файла
EXECUTABLE = program.exe

# Правило по умолчанию (сборка исполняемого файла)
all: clean build run

run:
	.\$(EXECUTABLE)

# Правило сборки исполняемого файла
build: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Очистка
clean:
	del $(EXECUTABLE)
