use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::vec::Vec;

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let mut result: Vec<String> = Vec::new();
    if let Ok(lines) = read_lines("./input") {
        for line in lines {
                if let Ok(l) = line {

                let full_line: Vec<String> = l.split_whitespace().map(str::to_string).collect();
                let policy = &full_line[0];
                let letter = &full_line[1];
                let password = &full_line[2];

                let password_chars: Vec<char> = password.chars().collect();

                let p: Vec<String> = policy.split("-").map(str::to_string).collect();
                let firstnum = &p[0].parse::<usize>().unwrap();
                let secondnum = &p[1].parse::<usize>().unwrap();

                let le = letter.trim_matches(':');

                if password.contains(&le) {
                    if password_chars[firstnum - 1] == le.parse().unwrap() && password_chars[secondnum - 1] != le.parse().unwrap() {
                        // println!("{} - {}", password_chars[0], le);
                        // println!("{} - {} - {}", policy, letter, password);
                        result.push(l)
                    } else if password_chars[firstnum - 1] != le.parse().unwrap() && password_chars[secondnum - 1] == le.parse().unwrap() {
                        result.push(l)
                    } else if password_chars[firstnum - 1] != le.parse().unwrap() && password_chars[secondnum - 1] != le.parse().unwrap() {
                        continue
                    } else if password_chars[firstnum - 1] == le.parse().unwrap() && password_chars[secondnum - 1] == le.parse().unwrap() {
                        continue
                    }
                    // let n = password.matches(&le).count();

                    // if &n >= firstnum && &n <= secondnum {
                    //     result.push(l);
                    // }
                }
            }
        }
    }
    println!("{}", result.len())
}