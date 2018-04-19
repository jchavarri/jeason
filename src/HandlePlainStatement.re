let mapper = (state, (_, statement)) =>
  Parser_flow.Ast.Statement.(
    switch (statement) {
    | VariableDeclaration({declarations}) =>
      Js.log("Var");
      let (_, {VariableDeclaration.Declarator.id: (_, id), init}) =
        List.hd(declarations);
      switch (init) {
      | Some(e) => HandleExpression.mapper(state, e)
      | None => state
      };
    | Return(_)
    | Expression(_)
    | If(_)
    | Block(_)
    | FunctionDeclaration(_)
    | Empty
    | ClassDeclaration(_)
    | ExportDefaultDeclaration(_)
    | ExportNamedDeclaration(_)
    | Labeled(_)
    | Break(_)
    | Continue(_)
    | With(_)
    | TypeAlias(_)
    | Switch(_)
    | Throw(_)
    | Try(_)
    | While(_)
    | DoWhile(_)
    | For(_)
    | ForIn(_)
    | ForOf(_)
    | Debugger
    | InterfaceDeclaration(_)
    | DeclareVariable(_)
    | DeclareFunction(_)
    | DeclareClass(_)
    | DeclareModule(_)
    | DeclareModuleExports(_)
    | DeclareExportDeclaration(_)
    | ImportDeclaration(_) => state
    }
  );