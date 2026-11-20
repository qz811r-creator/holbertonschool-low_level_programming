#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: First member (dog's name)
 * @age: Second member (dog's age)
 * @owner: Third member (owner's name)
 *
 * Description: Structure representing a dog with its name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
