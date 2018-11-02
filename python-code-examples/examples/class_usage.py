class Animal:  # Definition of a new Animal class:
    def __init__(self, sound):
        self.sound = sound

    def talk(self):
        print(f'{self.sound}')


class Dog(Animal):  # Definition of a Dog subclass:
    # Definition of a class level constant
    DOG_SOUND = 'woof'

    # Overriding super-class's constructor
    def __init__(self):
        # Calling super-class's constructor with value
        super(Dog, self).__init__(sound=self.DOG_SOUND)


# Initializing instances of each class
horse = Animal('Neigh')
dog = Dog()
animals = [horse, dog]

# Using polymorphism to make all the animals talk
for animal in animals:
    animal.talk()
