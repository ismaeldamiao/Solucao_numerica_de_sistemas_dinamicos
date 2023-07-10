#!/usr/bin/env bash

cd `dirname ${0}`

which clang > /dev/null && CC="clang" || CC="cc"
CC_FLAGS="-std=c99 -Wall -Wextra -Wpedantic"

${CC} ${CC_FLAGS} SIR.c -o `systemd-path temporary`/SIR -lm && {
   `systemd-path temporary`/SIR
   gnuplot SIR.gp
}
${CC} ${CC_FLAGS} oscilador.c -o `systemd-path temporary`/oscilador -lm && {
   `systemd-path temporary`/oscilador
   gnuplot oscilador.gp
}

exit 0
