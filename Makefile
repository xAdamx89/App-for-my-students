main.c: func.c
	gcc -Wall main.c func.c -o App_for_tests
	echo "Skompilowano plik"
func.c:
	echo "Sprawdzam main.c..."
clear:
	rm App_for_tests

#gcc -Wall - dobra praktyka

	