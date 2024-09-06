@echo off
:loop
    echo %%x
    python gen.py > in
    ac.exe < in > ac.out
    wa.exe < in > wa.out
    fc ac.out wa.out
if not errorlevel 1 goto loop