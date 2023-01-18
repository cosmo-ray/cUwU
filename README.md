I've try to make an [uwuify](https://docs.rs/uwuify/latest/uwuifier/index.html)-like in C, as I've made it in the train,
I didn't have access to uwuify source while coding this.

# Usage

Just include cuwu.h in your project.

# Dependancies 

None

# using cuwu in shell

```
gcc main.c -o cuwu; cat README.md | ./cuwu

cat README.md main.c cuwu.h | tcc -run main.c | less
```
