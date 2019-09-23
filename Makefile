NAME = ft_pacman

SRCS =	Cell.cpp\
        Food.cpp\
        Ghost.cpp\
        Graph.cpp\
        main.cpp\
        Object.cpp\
        Pacman.cpp\
        Point.cpp

INC	 =	Cell.hpp\
        Food.hpp\
        Ghost.hpp\
        Graph.hpp\
        Object.hpp\
        Pacman.hpp\
        Point.hpp

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building of $(NAME)..."
	@clang++ -o $(NAME) $(OBJ) -lncurses -std=c++11

%.o: %.cpp $(INC)
	clang++ -std=c++11 -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all