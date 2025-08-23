main.c: func.c
	echo "Znaleziono main.c"
	gcc -Wall main.c func.c -o App_for_tests
clear:
	rm App_for_tests

#gcc -Wall - dobra praktyka

	