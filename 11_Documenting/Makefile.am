SUBDIRS = src po 

@DX_RULES@

all-local: doxygen-doc

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

doxygen-doc/man/man1/guess.c.1: doxygen-doc

man1_MANS = doxygen-doc/man/man1/guess.c.1

TO_DEL = doxygen-doc html latex Doxyfile ABOUT-NLS autom4te.cache config.guess config.h.in config.log config.status configure install-sh Makefile Makefile.in stamp-h1 aclocal.m4 compile config.h config.h.in~ config.rpath config.sub configure~ depcomp m4 missing src/.deps src/guess.o src/guess src/Makefile src/Makefile.in po/boldquot.sed po/en@quot.header po/Makefile po/Makefile.in.in po/Makevars.template po/POTFILES po/remove-potcdate.sin po/Rules-quot po/stamp-it po/en@boldquot.header po/insert-header.sin po/Makefile.in po/Makefile.in.in~ po/quot.sed po/ru.gmo

clean:
	rm -rf $(TO_DEL)

http: doxygen-doc
	python3 -m http.server --directory $</html 8000
