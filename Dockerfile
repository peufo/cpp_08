FROM alpine:3
RUN apk add --no-cache zsh
RUN apk add --no-cache bash
RUN apk add --no-cache valgrind
RUN apk add --no-cache curl
RUN apk add --no-cache git
RUN apk add --no-cache gcc
RUN apk add --no-cache g++
RUN apk add --no-cache make
RUN apk add --no-cache gdb
RUN apk add --no-cache mandoc man-pages
RUN apk add --no-cache libc-dev
RUN apk add --no-cache readline-dev
RUN apk add --no-cache libxext-dev
RUN apk add --no-cache libbsd-dev
RUN apk add --no-cache zlib-dev
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
WORKDIR /app
ENTRYPOINT [ "/bin/zsh" ] 