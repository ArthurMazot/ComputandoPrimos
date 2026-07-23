MAX = 1000000

CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2
LDFLAGS ?= -lm

SRCDIR      := arquivos
RESULTS_DIR := resultados
TARGETS     := Compara Primos Primos1V0 Primos1V1 Primos2V0 Primos2V1 Primos2V2
RUN_TARGETS := Primos1V0 Primos1V1 Primos2V0 Primos2V1 Primos2V2

ifeq ($(OS),Windows_NT)
EXEEXT := .exe
else
EXEEXT :=
endif

BINARIES    := $(addsuffix $(EXEEXT),$(TARGETS))
RUN_BINARIES:= $(addsuffix $(EXEEXT),$(RUN_TARGETS))
SOURCES     := $(addprefix $(SRCDIR)/,$(addsuffix .c,$(TARGETS)))
RESULTS     := $(addprefix $(RESULTS_DIR)/,$(addsuffix .txt,$(RUN_TARGETS)))

.PHONY: all run clean
all: $(BINARIES)

$(BINARIES): %$(EXEEXT): $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

run: all | $(RESULTS_DIR)
	@echo "Escrevendo os resultados no diretório $(RESULTS_DIR)/"
	@for exe in $(RUN_BINARIES); do \
		echo "Executando $$exe"; \
		./$$exe $(MAX) > "$(RESULTS_DIR)/$${exe%$(EXEEXT)}.txt"; \
	done

$(RESULTS_DIR):
	@mkdir -p "$(RESULTS_DIR)"

clean:
	@echo "Limpando executáveis e resultados"
	@rm -f $(BINARIES) $(RESULTS)