TARGET1 = python .\binary_tree_create.py
TARGET2 = python .\tree_stats.py

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET = tree.txt
else
	RM = rm
	TARGET = tree
endif

all:
	$(TARGET1)

clean:
	$(RM) $(TARGET)

run: all
	$(TARGET2)

stats: 
	$(TARGET2)
