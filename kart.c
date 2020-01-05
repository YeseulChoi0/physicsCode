#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "kart.h"

const double CONSTANT_ACCEL = 10;
const double MAX_ACCEL = 100;


struct kart initialize(){
  struct kart A;
  A.position.x = 0;
  A.position.y = 0;
  A.velocity.x = 0;
  A.velocity.y = 0;
  A.acceleration.x = 0;
  A.acceleration.y = 0;
  return A;
}

struct kart set_position(struct kart cart, double x, double y){
  cart.position.x = x;
  cart.position.y = y;
  return cart;
}

struct kart set_acceleration(struct kart cart, double x, double y){
  cart.acceleration.x = x;
  cart.acceleration.y = y;
  return cart;
}
struct kart move(struct kart currentKart, int xdir, int ydir, double timePassed){
  currentKart = update_acceleration(currentKart, xdir, ydir);
  currentKart = update_position(currentKart, timePassed);
  currentKart = update_velocity(currentKart, timePassed);
  return currentKart;
}

struct kart update_position(struct kart currentKart, double timePassed){
  currentKart.position = vector_addition( currentKart.position, vector_addition(scalar_mult(currentKart.velocity, timePassed), scalar_mult(currentKart.acceleration, .5 * pow(timePassed, 2))));
  return currentKart;
}

struct kart update_velocity(struct kart currentKart, double timePassed){
  currentKart.velocity = vector_addition(currentKart.velocity, scalar_mult(currentKart.acceleration, timePassed));
  return currentKart;
}

struct kart update_acceleration(struct kart currentKart, int xdir, int ydir){//negative number for down, left, position for up, right, 0 for neither
  if (xdir == 0 || ydir == 0){
    currentKart.acceleration.x = add_acceleration(currentKart.acceleration.x, CONSTANT_ACCEL, ydir);
    currentKart.acceleration.y = add_acceleration(currentKart.acceleration.y, CONSTANT_ACCEL, xdir);
  }else{
    currentKart.acceleration.x = add_acceleration(currentKart.acceleration.x, sqrt(CONSTANT_ACCEL) / 2, ydir);
    currentKart.acceleration.y = add_acceleration(currentKart.acceleration.y, sqrt(CONSTANT_ACCEL) / 2, xdir);
  }
  return currentKart;
}

int add_acceleration(double currentA, double addition, int dir){
  double newA = currentA;
  if (dir < 0){
    newA = currentA - addition;
  }if (dir > 0){
    newA = currentA + addition;
  }
  return newA;
}

struct vector vector_addition(struct vector A, struct vector B){
  struct vector total;
  total.x = A.x + B.x;
  total.y = A.y + B.y;
  return total;
}

struct vector scalar_mult(struct vector A, double multiplier){
  A.x = A.x * multiplier;
  A.y = A.y * multiplier;
  return A;
}
