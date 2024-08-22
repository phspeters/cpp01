#include "sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed [filename] [original string] [new string] " << std::endl;
		return 1;
	}

	sed s(argv[1], argv[2], argv[3]);
	s.replace();
}
