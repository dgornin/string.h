CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGC=-c -Wall -Wextra -Werror
TEST_LIBS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
SOURCES=s21_string.c s21_sprintf.c s21_sscanf.c str_to_num.c
OBJECTS=$(SOURCES:.c=.o)
TEST_SOURCES=test_main.c $(wildcard tests/*.c)
TEST_OBJECTS=$(TEST_SOURCES:.c=.o)

ifeq ($(shell uname -s),Linux)
	TEST_LIBS += -lrt -lsubunit
endif

all: $(SOURCES) test

.c.o:
	$(CC) $(CFLAGC) $< -o $@

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

clean:
	rm -rf $(OBJECTS) $(TEST_OBJECTS) test *.gcov *.gcno *.gcda *.info report s21_string.a

soft_clean:
	rm -rf $(OBJECTS) $(TEST_OBJECTS) test *.gcov *.gcno *.gcda *.info s21_string.a

rebuild: clean all

style:
	clang-format -n s21_*.c
	clang-format -n s21_*.h

gcov_report: $(TEST_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TEST_OBJECTS) $(SOURCES) $(TEST_LIBS) -o test
	./test
	gcov *.gcno
	lcov -t "s21_string" -o s21_string.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report s21_string.info --rc lcov_branch_coverage=1

test: $(TEST_OBJECTS) s21_string.a
	$(CC) $^ -o test $(TEST_LIBS)
