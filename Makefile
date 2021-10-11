.PHONY: clean All

All:
	@echo "----------Building project:[ base85 - Debug ]----------"
	@"$(MAKE)" -f  "base85.mk"
clean:
	@echo "----------Cleaning project:[ base85 - Debug ]----------"
	@"$(MAKE)" -f  "base85.mk" clean
