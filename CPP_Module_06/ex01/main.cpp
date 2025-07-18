#include <iomanip>

#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data			original;
	original.id		= 69;
	original.name	= "Joao";
	original.age	= 25;

	uintptr_t	serialized = Serializer::serialize(&original);
	Data*		deserialized = Serializer::deserialize(serialized);

	std::cout << std::setw(14) << "original: " << &original << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;

	std::cout << std::endl << "--deserialized content--" << std::endl
			  << std::setw(6) << "id: " << deserialized->id << std::endl
			  << "name: " << deserialized->name << std::endl
			  << std::setw(6) << "age: " << deserialized->age << std::endl;

	return 0;
}