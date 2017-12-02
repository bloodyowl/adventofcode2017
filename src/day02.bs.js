// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List        = require("bs-platform/lib/js/list.js");
var $$Array     = require("bs-platform/lib/js/array.js");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

function solve(input) {
  return List.fold_left((function (acc, item) {
                var values = List.map(Caml_format.caml_int_of_string, $$Array.to_list(item.split((/\s+/))));
                return acc + (List.fold_left(Pervasives.max, 0, values) - List.fold_left(Pervasives.min, Pervasives.max_int, values) | 0) | 0;
              }), 0, $$Array.to_list(input.split("\n")));
}

exports.solve = solve;
/* No side effect */