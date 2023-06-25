SHELL = /bin/bash

SRCS_MACOS += main.c

SRC_PATH += ./src/

OBJS_PATH_LINUX = ./src/_Objet_L
OBJS_PATH_MACOS = ./src/_Objet_M

HEAD_PATH += -I ./src/_Include


OBJS_LINUX = ${patsubst %.c, ${OBJS_PATH_LINUX}/%.o, ${SRCS_LINUX}}
OBJS_MACOS = ${patsubst %.c, ${OBJS_PATH_MACOS}/%.o, ${SRCS_MACOS}}


NAME = snake
CC = cc

CFLAGS = -Wall -Werror -Wextra -g
CFLAGS_LINUX = -Wall -Werror -Wextra -lmlx -lm -lXext -MMD -lX11 -I ./lib/minilibx-linux -L ./lib/minilibx-linux
FLAGSMACOS = -g3 -fsanitize=address -lmlx -framework OpenGL -framework AppKit -MMD -I ./lib/minilibx_macos -L ./lib/minilibx_macos



vpath %.c ${SRC_PATH}
vpath %.h ${HEAD_PATH}


all:  ${OBJS_LINUX}
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx-linux/
	@	${CC}  -o ${NAME} ${OBJS_LINUX} ${HEAD_PATH} ${CFLAGS_LINUX} -D OS=0
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"

# all:
#	  @	echo -e "\nmake "$(LIGHTRED)"linux"$(NC)"/"$(LIGHTCYAN)"macos"$(NC)" && ./cub3d ./map/*.cub\n"

linux:  ${OBJS_LINUX}
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx-linux/
	@	${CC}  -o ${NAME} ${OBJS_LINUX} ${HEAD_PATH} ${CFLAGS_LINUX} -D OS=0
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"

macos: ${OBJS_MACOS}
	@	$(MAKE) --no-print-directory -s -C ./lib/minilibx_macos/
	@	${CC} -o ${NAME} ${OBJS_MACOS}  ${HEAD_PATH} ${FLAGSMACOS} 
	@	echo -ne "\r\033[2K" $(LIGHTGREEN) "\t$(NAME) OK" "\033[0m" "\n"

valgrind: all
	valgrind ./${NAME}


${OBJS_MACOS}: ${OBJS_PATH_MACOS}/%.o: %.c Makefile ./src/_Include/cub3d.h
	@	mkdir -p ${OBJS_PATH_MACOS}
	@	$(COLORCOMPIL)
	@	${CC} -D OS=0 ${CFLAGS} -c $< -o $@ ${HEAD_PATH}


${OBJS_LINUX}: ${OBJS_PATH_LINUX}/%.o: %.c Makefile ./src/_Include/cub3d.h
	@	mkdir -p ${OBJS_PATH_LINUX}
	@	$(COLORCOMPIL)
	@	${CC} -D OS=1 ${CFLAGS} -c $< -o $@ ${HEAD_PATH}


clean:
	@	echo -ne "\r\033[2K" $(YELLOW) "Cleaning\n\n"$(NC)
	@	rm -rf ${OBJS_PATH_LINUX}
	@	rm -rf ${OBJS_PATH_MACOS}


fclean: clean
	@	rm -f ${NAME}
	@	echo -ne "\r\033[2K" $(GREEN) "\t$(NAME) Remove\n"$(NC)"\n"




re: fclean
	@	echo -ne "\r\033[2K" $(YELLOW) "Rebuilding..."$(NC)"\n""\n"
	@	$(MAKE) -s


.PHONY: re clean fclean 

NC='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'

DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
YELLOW='\033[1;33m'
WHITE='\033[1;37m'


ifndef COLORCOMPIL
COLORCOMPIL = \
	if [ "$(shell test $P -lt 33; echo $$?)" = "0" ]; then \
    	echo -ne "\r\033[2K" $(LIGHTRED) "[$(P)%] "$(DARKGRAY) "Compiling Cub3d" $(WHITE) "$<"; \
	else \
		if [ "$(shell test $P -lt 66; echo $$?)" = "0" ]; then \
    		echo -ne "\r\033[2K" $(YELLOW) "[$(P)%]" $(DARKGRAY) "Compiling Cub3d" $(WHITE) "$<"; \
		else \
       		echo -ne "\r\033[2K" $(LIGHTGREEN) "[$(P)%]" $(DARKGRAY) "Compiling Cub3d" $(WHITE) "$<"; \
		fi \
	fi
T := $(words $(SRCS_MACOS))
N := x
C = $(words $N)$(eval N := x $N)
P = `expr $C '*' 100 / $T / 5`
endif