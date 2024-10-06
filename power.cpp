#include "util.h"
#include "padel.h"

#include "ball.h"
#include "power.h"
#include "util.h"


greenPowerUp::greenPowerUp() : xg(450), yg(750), greenstatus(false) {}

void greenPowerUp::set_xg(int xg) {
    this->xg = xg;
}

int greenPowerUp::get_xg() {
    return xg;
}

void greenPowerUp::set_yg(int yg) {
    this->yg = yg;
}

int greenPowerUp::get_yg() {
    return yg;
}

void greenPowerUp::display() {
    // if(Greenstatus()==true)
    DrawTriangle(xg, yg, xg+30, yg+30, xg+30, yg, colors[GREEN]);
}

bool greenPowerUp::Greenstatus() {
    return greenstatus;
}

void greenPowerUp::setGreenstatus(bool greenstatus) {
    this->greenstatus = greenstatus;
}









pinkPowerup::pinkPowerup():xp(450), yp(650), pinkstatus(false){}
void pinkPowerup::set_xp(int xp) {
    this->xp = xp;
}

int pinkPowerup::get_xp() {
    return this->xp;
}

void pinkPowerup::set_yp(int yp) {
    this->yp = yp;
}

int pinkPowerup::get_yp() {
    return this->yp;
}

void pinkPowerup::displaypink() {
    DrawSquare(xp,yp,20,colors[PINK]);
}

bool pinkPowerup::getpinkstatus() {
    return pinkstatus;
}

void pinkPowerup::setpinkstatus(bool pinkstatus) {
    this->pinkstatus = pinkstatus;
}







bluePowerup::bluePowerup():xb(450), yb(550), bluestatus(false){}
void bluePowerup::set_xb(int xb) {
    this->xb = xb;
}

int bluePowerup::get_xb() {
    return this->xb;
}

void bluePowerup::set_yb(int yb) {
    this->yb = yb;
}

int bluePowerup::get_yb() {
    return this->yb;
}

void bluePowerup::displayblue() {
    DrawCircle(xb,yb,10,colors[BLUE]);
}

bool bluePowerup::getbluestatus() {
    return bluestatus;
}

void bluePowerup::setbluestatus(bool bluestatus) {
    this->bluestatus = bluestatus;
}















redPowerup::redPowerup():xr(450), yr(550), redstatus(false){}
void redPowerup::set_xr(int xr) {
    this->xr = xr;
}

int redPowerup::get_xr() {
    return this->xr;
}

void redPowerup::set_yr(int yr) {
    this->yr = yr;
}

int redPowerup::get_yr() {
    return this->yr;
}

void redPowerup::displayred() {
    DrawCircle(xr,yr,10,colors[RED]);
}

bool redPowerup::getredstatus() {
    return redstatus;
}

void redPowerup::setredstatus(bool redstatus) {
    this->redstatus = redstatus;
}















yellowPowerup::yellowPowerup():xy(450), yy(600), yellowstatus(false){}
void yellowPowerup::set_xy(int xy) {
    this->xy = xy;
}

int yellowPowerup::get_xy() {
    return this->xy;
}

void yellowPowerup::set_yy(int yy) {
    this->yy = yy;
}

int yellowPowerup::get_yy() {
    return this->yy;
}

void yellowPowerup::displayyellow() {
    DrawSquare(xy,yy,20,colors[YELLOW]);
}

bool yellowPowerup::getyellowstatus() {
    return yellowstatus;
}

void yellowPowerup::setyellowstatus(bool yellowstatus) {
    this->yellowstatus = yellowstatus;
}

void yellowPowerup::setnewBallstatus(bool newballstatus){
    this->newballstatus = newballstatus;
}

bool yellowPowerup::getnewBallstatus(){
    return newballstatus;
}