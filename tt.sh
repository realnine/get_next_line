#!/bin/bash

gcc -Wall -Werror -Wextra -g get_next_line.c get_next_line_utils.c gnl_tester.c -D BUFFER_SIZE=42 && ./a.out
