compile:
	ant

install:
	mkdir -p /usr/lib/adversaria
	cp dist/Adversaria.jar /usr/lib/adversaria/
	echo "#!/bin/sh\njava -jar /usr/lib/adversaria/Adversaria.jar" > /usr/bin/adversaria
	chmod +x /usr/bin/adversaria

.PHONY: compile install
