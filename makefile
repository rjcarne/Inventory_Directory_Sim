build:
	g++ -Wall -g Address.cpp Functions.cpp Car.cpp Date.cpp driver.cpp Inventory.cpp Person.cpp Truck.cpp Vehicle.cpp -std=c++11 -o letsrunthis

run: build
	./letsrunthis inventory.txt out.txt removeNames.txt

clean:
	rm vehicleOut100.txt customerOut100.txt customerOutEC2.txt customerOutEC1.txt letsrunthis
