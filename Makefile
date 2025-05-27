run: esimerkki.prg
	x64sc esimerkki.prg

esimerkki.prg: esimerkki.c Makefile
	cl65 -Cc64.cfg -o esimerkki.prg esimerkki.c 

clean:
	rm *.prg; true


