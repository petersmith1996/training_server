g++ -o sim test_sim.cpp ./sample/j2735.c ./sample/bsm.c ./sample/pvd.c -I ./ -I ./j2735/ -L ./j2735/ -lasncodec -g -pthread -ljson-c
