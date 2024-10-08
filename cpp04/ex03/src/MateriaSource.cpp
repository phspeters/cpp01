#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _learntMaterias(), _createdMaterias() {}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < MATERIAS_INVENTORY; i++)
	{
		if (copy._learntMaterias[i])
		{
			_learntMaterias[i] = copy._learntMaterias[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MATERIAS_INVENTORY; i++)
	{
		if (_learntMaterias[i])
		{
			delete _learntMaterias[i];
			_learntMaterias[i] = NULL;
		}
	}
	
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (_createdMaterias[i])
		{
			delete _createdMaterias[i];
			_createdMaterias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MATERIAS_INVENTORY; i++)
		{
			delete _learntMaterias[i];
			_learntMaterias[i] = NULL;
		}
		for (int i = 0; i < MATERIAS_INVENTORY; i++)
		{
			if (copy._learntMaterias[i])
			{
				_learntMaterias[i] = copy._learntMaterias[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MATERIAS_INVENTORY; i++)
	{
		if (!_learntMaterias[i])
		{
			_learntMaterias[i] = materia->clone();
			break;
		}

		if (i == 3)
			std::cerr << "MateriaSource: No more space to learn new materia\n";
	}

	manageMaterias(materia);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MATERIAS_INVENTORY; i++)
	{
		if (_learntMaterias[i] && _learntMaterias[i]->getType() == type)
		{
			AMateria *newMateria = _learntMaterias[i]->clone();
			manageMaterias(newMateria);
			return (newMateria);
		}
	}
	return (NULL);
}

void MateriaSource::manageMaterias(AMateria *materia)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!_createdMaterias[i])
		{
			_createdMaterias[i] = materia;
			return;
		}
	}

	std::cerr << "MateriaSource: No more space for new materia in this simulation\n";
	std::cerr << "Deleting the last created materia\n";
	delete materia;
}