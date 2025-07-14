all: vehicle
	./vehicle

vehicle: main.c car.c
	gcc main.c car.c -o vehicle

clean:
	rm -f vehicle
