open Ast_helper;

let transform = structureItems =>
  structureItems
  |> List.map(structureItem =>
       switch (structureItem) {
       | Types.AbstractType
       | ExternalModule =>
         Str.primitive({
           pval_name: {
             loc: default_loc.contents,
             txt: "make",
           },
           pval_prim: [""],
           pval_loc: default_loc.contents,
           pval_type: {
             ptyp_desc:
               Ptyp_arrow(
                 "",
                 {
                   ptyp_loc: default_loc.contents,
                   ptyp_attributes: [],
                   ptyp_desc:
                     Ptyp_constr(
                       AstUtils.astHelperStrLidIdent(["string"]),
                       [],
                     ),
                 },
                 {
                   ptyp_loc: default_loc.contents,
                   ptyp_attributes: [],
                   ptyp_desc:
                     Ptyp_constr(
                       AstUtils.astHelperStrLidIdent(["nano"]),
                       [],
                     ),
                 },
               ),
             ptyp_loc: default_loc.contents,
             ptyp_attributes: [],
           },
           pval_attributes: [
             ({loc: default_loc.contents, txt: "bs.module"}, PStr([])),
           ],
         })
       }
     );