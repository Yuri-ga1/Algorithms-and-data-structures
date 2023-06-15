PJW = python .\PJW.py
CRC = python .\CRC.py
TREE = python .\tree.py

ifeq ($(OS), Windows_NT)
	RM = del
else
	RM = rm
endif

pjw:
	$(PJW)

crc:
	$(CRC)

tree_pjw:
	$(PJW) | $(TREE)

tree_crc:
	$(CRC) | $(TREE)
