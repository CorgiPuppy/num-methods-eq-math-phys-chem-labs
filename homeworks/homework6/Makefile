REPORT_DIR := report

RPRT := $(REPORT_DIR)/report.pdf

PDFLTX := pdflatex
ZTHR := zathura

OUTPUT := --output-directory

.PHONY: all

all: clean-report run-report clean-aux

run-report: $(RPRT)
	@echo "Running a report.."
	@$(ZTHR) $<

$(RPRT): $(REPORT_DIR)/*.tex
	@echo "Building pdf.."
	$(PDFLTX) $(OUTPUT)=$(REPORT_DIR) $<
	$(PDFLTX) $(OUTPUT)=$(REPORT_DIR) $<

clean-aux:
	@echo "Cleaning up auxiliary files.."
	@find $(REPORT_DIR) -type f ! -name '*.pdf' ! -name '*.tex' -delete

clean-report:
	@echo "Cleaning the report.."
	@$(RM) $(RPRT)
