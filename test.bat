@echo off
dvsim.exe < data/%1.in > data/%1.test.out
cd data
fc %1.out %1.test.out
rm %1.test.out
cd ../