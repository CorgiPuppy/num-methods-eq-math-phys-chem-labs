SRC_DIR := src
REPORT_DIR := report

RPRT := $(REPORT_DIR)/report.pdf
SRC := $(wildcard $(SRC_DIR)/*.hs)

TPST := typst compile --root .
ZTHR := zathura

.PHONY: all

all: clean-report run-src run-report 

run-src: $(SRC)
	@echo "Running main.."

run-report: $(RPRT)
	@echo "Running a report.."
	@$(ZTHR) $<	

$(RPRT): $(REPORT_DIR)/*.typ
	@echo "Building pdf.."
	@$(TPST) $<

clean-report: 
	@echo "Cleaning the report.."
	@$(RM) $(RPRT)
