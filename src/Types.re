type externalType =
  | String
  | Unit
  | Arrow(externalType, externalType);

type statement =
  | AbstractType
  | ExternalModule;

type state = {
  identifiers: list(string),
  outputStatements: list(statement),
};

module type Statement = {
  let mapper: (state, Parser_flow.Ast.Statement.t) => state;
};

module type T = {let mapper: (state, Parser_flow.Ast.Statement.t) => state;};