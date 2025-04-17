(*
  Program: Statistics Calculator (OCaml Version with User Input)
  This version allows the user to input a list of integers.
  It calculates Mean, Median, and Mode using functional style.
*)

(* Helper to split a string into a list of integers *)
let parse_input input =
  input
  |> String.split_on_char ' '
  |> List.filter (fun s -> s <> "")
  |> List.map int_of_string

(* Calculate mean *)
let calculate_mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  let count = List.length lst in
  float_of_int sum /. float_of_int count

(* Sort a list *)
let sort_list lst = List.sort compare lst

(* Calculate median *)
let calculate_median lst =
  let sorted = sort_list lst in
  let len = List.length sorted in
  if len mod 2 = 1 then
    float_of_int (List.nth sorted (len / 2))
  else
    let mid1 = List.nth sorted (len / 2 - 1) in
    let mid2 = List.nth sorted (len / 2) in
    float_of_int (mid1 + mid2) /. 2.0

(* Count frequencies *)
let count_frequencies lst =
  let update_count map num =
    if List.mem_assoc num map then
      (num, (List.assoc num map) + 1) :: (List.remove_assoc num map)
    else
      (num, 1) :: map
  in
  List.fold_left update_count [] lst

(* Calculate mode *)
let calculate_mode lst =
  let freq_list = count_frequencies lst in
  let max_freq = List.fold_left (fun acc (_, freq) -> max acc freq) 0 freq_list in
  List.fold_left (fun acc (num, freq) ->
    if freq = max_freq then num :: acc else acc
  ) [] freq_list
  |> sort_list

(* MAIN *)
let () =
  print_endline "Enter integers separated by space:";
  let input = read_line () in
  let numbers =
    try parse_input input
    with Failure _ ->
      print_endline "Invalid input. Please enter only integers.";
      exit 1
  in

  Printf.printf "Input Numbers: ";
  List.iter (fun x -> Printf.printf "%d " x) numbers;
  Printf.printf "\n";

  let mean = calculate_mean numbers in
  let median = calculate_median numbers in
  let mode = calculate_mode numbers in

  Printf.printf "Mean: %.2f\n" mean;
  Printf.printf "Median: %.2f\n" median;
  Printf.printf "Mode: ";
  List.iter (fun x -> Printf.printf "%d " x) mode;
  Printf.printf "\n"