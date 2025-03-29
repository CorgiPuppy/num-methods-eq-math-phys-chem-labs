SRC_DIR := src
REPORT_DIR := report

RPRT := $(REPORT_DIR)/report.pdf
SRC := $(wildcard $(SRC_DIR)/*.sh)

BSH := bash
PDFLTX := pdflatex
ZTHR := zathura

OUTPUT := --output-directory

.PHONY: all

all: clean-report run-src run-report clean-aux

run-src: $(SRC)
	@echo "Running main.."
	@$(BSH) $<

run-report: $(RPRT)
	@echo "Running report.."
	@$(ZTHR) $<	

$(RPRT): $(REPORT_DIR)/*.tex
	@echo "Building pdf.."
	$(PDFLTX) $(OUTPUT)=$(REPORT_DIR) $<
	$(PDFLTX) $(OUTPUT)=$(REPORT_DIR) $<

clean-aux:
	@echo "Cleaning up auxiliary files.."
	@find $(REPORT_DIR) -type f ! -name '*.pdf' ! -name '*.tex' -delete	

clean-report: 
	@echo "Cleaning up.."
	@$(RM) $(RPRT)
