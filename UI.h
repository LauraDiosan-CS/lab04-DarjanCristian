#pragma once
#include "Service.h"
#include "Spending.h"

class UI {
private:
    Service service;
    void displayMenu();
    void uiAddSpending(string cmd);
    void uiShowAll();
    void uiUpdate(string cmd);
    void uiDeleteByApartment(string cmd);
    void uiDeleteId(string cmd);
    void uiDeleteAps(string cmd);
    void uiDeleteType(string cmd);
    void uiShowAp(string cmd);
    void uiShowRulePrice(string cmd);
    void uiSumType(string cmd);
    void uiSumApartment(string cmd);
    void uiMaxApartment(string cmd);
    void uiFilterType(string cmd);
    void uiSortedType(string cmd);
    void uiFilterPrice(string cmd);
public:
    UI();
    UI(Service& service);
    void runUI();
};