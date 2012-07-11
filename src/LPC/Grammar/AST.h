#ifndef Yggdrasil_AST_h
#define Yggdrasil_AST_h

namespace LPC {
namespace Grammar {

class CodeGenContext;
class Statement;
class Expression;
class VariableDeclaration;

typedef std::vector<Statement*>           StatementList;
typedef std::vector<Expression*>          ExpressionList;
typedef std::vector<VariableDeclaration*> VariableList;

clase Node {
public:
  virtual ~Node() {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class Expression : Node {
};

class Statement : Node {
};

class Integer : Expression {
public:
  long long value;
  Integer(long long value) : value(value) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class Float : Expression {
public:
  double value;
  Float(double value) : value(value) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class Identifier : public Expression {
public:
  std::string name;
  Identifier(const std::string& name) : name(name) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class MethodCall : public Expression {
public
  const Identifier& id;
  ExpressionList arguments;
  MethodCall(const Identifier& id, ExpressionList& arguments) :
    id(id), arguments(arguments) {}
  Methodcall(const Identifier& id) : id(id) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class BinaryOperator : public Expression {
public:
  Expression& lhs
  int op;
  Expression& rhs;
  BinaryOperator(Expression& lhs, int op, Expression& rhs) :
    lhs(lhs), op(op), rhs(rhs) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class Assignment : public Expression {
public:
  Identifier& lhs;
  Expression& rhs;
  Assignment(Identifier& lhs, Expression& rhs) :
    lhs(lhs), rhs(rhs) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class Block : public Expression {
public:
  StatementList statements;
  Block() {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
}

class ExpressionStatement : public Statement {
public:
  Expression& expr;
  ExpressionStatement(Expression& expr) : expr(expr) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class VariableDeclaration : public Statement {
public:
  const Identifier& type;
  Identifier& id;
  Expression* assignmentExpr;
  VariableDeclaration(const Identifier& type, Identifier& id) :
    type(type), id(id) {}
  VariableDeclaration(const Identifier& type, Identifier& id,
                      Expresion& assignmentExpr) : 
    type(type), id(id), assignment(assignment) {}    
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};

class FunctionDeclaration : public Statement {
public:
  const Identifier& type;
  const Identifier& id;
  VariableList arguments;
  Block& block;
  FunctionDeclaration(const Identifier& type, const Identifier& id,
                      const VariableList& arguments, Block& block) :
    type(type), id(id), arguments(arguments), block(block) {}
  //virtual llvm::Value *codeGen(CodeGenContext &context) = 0;
};





} /* namespace Grammar */
} /* namespace LPC */


#endif
