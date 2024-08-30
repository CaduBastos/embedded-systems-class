package = jupiter
version = 1.0
tarname = $(package)
distdir = $(tarname)-$(version)

# just invoke Makefile into subdirectories

.PHONY: all clean dist FORCE distcheck

all clean jupiter: 
	cd src && $(MAKE) $@

# creates the distribuiton package
dist: $(distdir).tar.gz

# compress the directory to be shipped and deletes the temporary folder
$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

# creates the directory to be shipped and copies the files into it
$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp Makefile $(distdir)
	cp src/Makefile src/main.c $(distdir)/src

# unpack the tarrball, compile the project and check if it's everything fine
distcheck: $(distdir).tar.gz	
	gzip -cd $(distdir).tar.gz | tar xvf -
	cd $(distdir) && $(MAKE) all	
	cd $(distdir) && $(MAKE) clean 
	rm -rf $(distdir)
	@echo "*** Package $(distdir).tar.gz is ready for distribuiton"

#forces the cleaning of previous generated distribution files
FORCE:
	-rm $(distdir).tar.gz > /dev/null 2>&1
	rm -rf $(distdir)

