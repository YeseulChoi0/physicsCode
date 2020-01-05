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

struct kart setPosition(struct kart cart, double x, double y){
  cart.position.x = x;
  cart.position.y = y;
  return cart;
}

struct kart setAcceleration(struct kart cart, double x, double y){
  cart.acceleration.x = x;
  cart.acceleration.y = y;
  return cart;
}
struct kart move(struct kart currentKart, int xdir, int ydir, double timePassed){
  currentKart = updateAcceleration(currentKart, timePassed);
  currentKart = updatePosition(currentKart, timePassed);
  currentKart = updateVelocity(currentKart, xdir, ydir, timePassed);
  return currentKart;
}

struct kart updatePosition(struct kart currentKart, double timePassed){
  vt + 1/2 at^2
  currentKart.position = vectorAddition( currentKart.position, vectorAddition(scalarMult(currentKart.velocity, timePassed) scalarMult(.5 * pow(timePassed, 2))))
  return currentKart;
}

struct kart updateVelocity(struct kart currentKart, double timePassed){
  currentKart.velocity = vectorAddition(currentKart.velocity, scalarMult(currentKart.acceleration, timePassed));
  return currentKart;
}

struct kart updateAcceleration(struct kart currentKart, int xdir, int ydir){//negative number for down, left, position for up, right, 0 for neither
  if (xdir == 0 || ydir == 0){
    currentKart.acceleration.x = addacceleration(currentKart.acceleration.x, CONSTANT_ACCEL, ydir);
    currentKart.acceleration.y = addacceleration(currentKart.acceleration.y, CONSTANT_ACCEL, xdir);
  }else{
    currentKart.acceleration.x = addacceleration(currentKart.acceleration.x, sqrt(CONSTANT_ACCEL) / 2, ydir);
    currentKart.acceleration.y = addacceleration(currentKart.acceleration.y, sqrt(CONSTANT_ACCEL) / 2, xdir);
  }
  return currentKart;
}

int addacceleration(double currentA, double addition, int dir){
  double newA = currentA;
  if (dir < 0){
    newA = currentA - addition;
  }if (dir > 0){
    newA = currentA + addition;
  }
  return newA;
}

struct vector vectorAddition(struct vector A, struct vector B){
  struct vector total;
  total.x = A.x + B.x;
  total.y = A.y + B.y;
  return total;
}

struct vector scalarMult(struct vector A, double multiplier){
  A.x = A.x * multiplier;
  A.y = A.y * multiplier;
  return A;
}
