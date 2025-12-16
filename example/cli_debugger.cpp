#include <iostream>
#include <string>
#include <vector>
#include "scripting/Debugger.h"
#include "scripting/Parser.h"

void runDebugger()
{
    using namespace std;

    cout << "Enter an expression at the prompt and then Enter to see the parsed tree.\n";
    cout << "Enter quit at the prompt to stop.\n";

    cout << ">> ";
    string evtStr;
    getline(cin, evtStr);

    while (evtStr != "quit")
    {
        try
        {
            Event exprTrees = parse(evtStr);
            for (const auto& exprTree : exprTrees)
            {
                Debugger debug;
                exprTree->acceptVisitor(debug);
                cout << debug.getString() << endl;
            }
        }
        catch (const script_error& e)
        {
            cout << e.what() << endl;
        }

        cout << ">> ";
        getline(cin, evtStr);
    }
}

int main(int argc, char* argv[])
{
    runDebugger();

    return 0;
}
