#ifndef CORE_H_
#define CORE_H_

#define new(x) (x*)malloc(sizeof(x))

#define new_array(x, size) (x*)malloc(sizeof(x) * size)

#define new_designate_array(x, size, ...)\
memcpy(malloc(sizeof(x) * size),   \
    &(x[size]){ __VA_ARGS__ },\
    sizeof(x) * size)

#define designate_new(x, ...)       \
  memcpy(malloc(sizeof(x)),         \
         &(x const){ __VA_ARGS__ }, \
         sizeof(x))

#define delete(x) free(x);

void CreateWindow();

void ResetWindow();

int  CloseWindow();

void RunGame(struct Game* game);

#endif
