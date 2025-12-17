#include <iostream>
#include <string>
#include <vector>
#include "scripting/Evaluator.h"
#include "scripting/Parser.h"

void runEvaluator()
{
    using namespace std;

    string exprStr;
    exprStr += "x = log(100)\n";
    exprStr += "y = 3 * x\n";
    exprStr += "if y < 50\n";
    exprStr += "then y = 50 z = 100\n";
    exprStr += "else z = y\n";
    exprStr += "endif";

    Event exprTrees = parse(exprStr);

    VarIndexer indexer;
    for (auto& exprTree : exprTrees)
        indexer.visit(exprTree);

    vector<string> varNames = indexer.getVarNames();
    Evaluator<double> evaluator(varNames.size());
    for (const auto& exprTree : exprTrees)
        evaluator.visit(exprTree);

    size_t idx = 0;
    for (const auto& val : evaluator.varVals())
        cout << "var[" << idx++ << "], " << varNames[idx-1] << " = " << val << endl;
}

int main(int argc, char* argv[])
{
    runEvaluator();

    return 0;
}
