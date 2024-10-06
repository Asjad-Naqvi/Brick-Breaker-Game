#include "util.h"

#include "menu.h"

menu::menu() {
    status = false;
}

bool menu::checkstatus() {
    return status;
}

void menu::setstatus(bool status) {
    this->status = status;
}