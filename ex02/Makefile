NAME 		= animal
SRC_DIR		= ./
SRC 		= 	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Animal.cpp \
				$(SRC_DIR)/Cat.cpp \
				$(SRC_DIR)/Dog.cpp \
				$(SRC_DIR)/WrongAnimal.cpp \
				$(SRC_DIR)/WrongCat.cpp \
				$(SRC_DIR)/Brain.cpp \

CC 			= c++
INCLUDES	= 
CFLAGS 		= -Wall -Werror -Wextra -std=c++98 -Wshadow $(INCLUDES)
OBJECTS		= 	$(SRC:.cpp=.o)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(OBJECTS)
	@clear
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean:
	@clear
	@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re test
