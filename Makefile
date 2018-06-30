HEADER_INSTALL_PATH = /usr/local/include

HEADERS = ethereum.h ewasm-types.h ewasm-eei.h ewasm-arith.h ewasm-bitwise.h ewasm-eei-helpers.h

all: install

install:
	for FILE in $(HEADERS); do \
		sudo cp $$FILE $(HEADER_INSTALL_PATH)/$$FILE; \
	done
