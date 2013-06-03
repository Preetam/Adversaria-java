compile:
	ant

install:
	mkdir -p /usr/lib/adversaria
	cp dist/Adversaria.jar /usr/lib/adversaria/

.PHONY: compile install
