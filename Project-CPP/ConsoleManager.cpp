#include "ConsoleManager.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include "MainConsole.h"
#include "MarqueeConsole.h"

typedef std::string String;

ConsoleManager* ConsoleManager::sharedInstance = nullptr;
ConsoleManager* ConsoleManager::getInstance()
{
    return sharedInstance;
}

void ConsoleManager::initialize()
{
    sharedInstance = new ConsoleManager();
}

void ConsoleManager::destroy()
{
    delete sharedInstance;
}

void ConsoleManager::drawConsole() const
{
    if(this->currentConsole != nullptr)
    {
        this->currentConsole->display();
    }
    else
    {
        std::cerr << "There is no assigned console." << std::endl;
    }
}

// TODO:

ConsoleManager::ConsoleManager()
{
    this->running = true;

    this->consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    const std::shared_ptr<MainConsole> mainConsole = std::make_shared<MainConsole>();
    const std::shared_ptr<MarqueeConsole> marqueeConsole = std::make_shared<MarqueeConsole>();

    this->consoleTable[MAIN_CONSOLE] = mainConsole;
    this->consoleTable[MARQUEE_CONSOLE] = marqueeConsole;

    this->switchConsole(MAIN_CONSOLE);
}

void ConsoleManager::process() const
{
    if(this->currentConsole != nullptr)
    {
        this->currentConsole->process();
    }
    else
    {
        std::cerr << "There is no assigned console." << std::endl;
    }
}

void ConsoleManager::switchConsole(String consoleName)
{
    if(this->consoleTable.contains(consoleName))
    {
        system("cls");
        this->previousConsole = this->curretnConsole;
        this->currentConsole = this->consoleTable[consoleName];
        this->currentConsole->onEnabled();
    }
    else
    {
        std::cerr << "Console name " << consoleName << " not initizalied." << std::endl; 
    }
}

void ConsoleManager::registerScreen(std::shared_ptr<Screen> screenRef)
{
    if(this->consoleTable.contains(screenRef->getName()))
    {
        std::cerr << "Screen name " << screenRef->getName() << "already exists." << std:endl;
        return;
    }

    this->consoleTable[screenRef->getName()] = screenRef;
}

void ConsoleManager::switchToScreen(String screenName)
{
    if(this->consoleTable.contains(screenName))
    {
        system("cls");
        this->previouseConsole = this->currentConsole;
        this->currentConsole = this->consoleTable[screenName];
        this->currentConsole->onEnabled();
    }
    else
    {
        std::cerr << "Screen name " << screenName << " not found." << std::endl;
    }
}


