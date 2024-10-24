#!/bin/bash

show_header() {
    clear
    echo "       ___  _____   _     _     _                 "
    echo "      /   |/ __  \ | |   (_)   | |                "
    echo "     / /| |\`' / /' | |    _ ___| |__   ___  _ __  "
    echo "    / /_| |  / /   | |   | / __| '_ \ / _ \| '_ \ "
    echo "    \___  |./ /___ | |___| \__ \ |_) | (_) | | | |"
    echo "        |_/\_____/ \_____/_|___/_.__/ \___/|_| |_|"
    echo "    ______                         _              "
    echo "    | ___ \                       | |             "
    echo "    | |_/ / __ ___  ___  ___ _ __ | |_ ___        "
    echo "    |  __/ '__/ _ \/ __|/ _ \ '_ \| __/ __|       "
    echo "    | |  | | |  __/\__ \  __/ | | | |_\__ \_ _ _  "
    echo "    \_|  |_|  \___||___/\___|_| |_|\__|___(_|_|_) "
    echo "                                              "
    echo "                                              "
    sleep 3

    clear
    echo "    ______     _                 _          _    "
    echo "    | ___ \   | |               | |        | |   "
    echo "    | |_/ /___| | ___   __ _  __| | ___  __| |   "
    echo "    |    // _ \ |/ _ \ / _\` |/ _\` |/ _ \/ _\` |   "
    echo "    | |\ \  __/ | (_) | (_| | (_| |  __/ (_| |   "
    echo "    \_| \_\___|_|\___/ \__,_|\__,_|\___|\__,_|   "
    echo "     _____           _ _                         "
    echo "    /  __ \         | (_)                        "
    echo "    | /  \/ ___   __| |_ _ __   __ _             "
    echo "    | |    / _ \ / _\` | | '_ \ / _\` |            "
    echo "    | \__/\ (_) | (_| | | | | | (_| |            "
    echo "     \____/\___/ \__,_|_|_| |_|\__, |            "
    echo "     _____ _           _ _      __/ |            "
    echo "    /  __ \ |         | | |   |___/             "
    echo "    | /  \/ |__   __ _| | | ___ _ __   __ _  ___ "
    echo "    | |   | '_ \ / _\` | | |/ _ \ '_ \ / _\` |/ _ \\"
    echo "    | \__/\ | | | (_| | | |  __/ | | | (_| |  __/"
    echo "     \____/_| |_|\__,_|_|_|\___|_| |_|\__, |\___|"
    echo "                                       __/ |     "
    echo "                                      |___/      "
}

show_header

function print_error() {
    echo -e "\t\033[31m$1\033[0m"
    sleep 1
}

function print_success() {
    echo -e "\t\033[32m$1\033[0m"
    sleep 1
}

while true; do
    echo -e "\n\t\033[36mLet's get started? Enter your intra username and then press 'Enter':\033[0m"
    read username

    if [[ -z "$username" ]]; then
        print_error "Username cannot be empty! Please enter a valid username."
    else
        break
    fi
done

output_file="${username}-ranking.txt"
>"$output_file"

echo -e "\n\tRanking results by: $username" >>"$output_file"
echo -e "\t==============================" >>"$output_file"

function display_header() {
    echo -e "\n\t\033[36m$1\033[0m"
    sleep 1
}

args=(
    "123"
    "ABBCCC"
    "\\"\\""
    ""
    $'\t(ASCII tab)'
    "Don't Panic!"
)

for arg in "${args[@]}"; do
    echo -e "Argument: '$arg'"
done

for dir in */; do
    if [[ -f "${dir}/count_and_say.c" ]]; then
        clear

        display_header "Running norminette for the current code: ${dir}"
        sleep 2

        norminette "${dir}/count_and_say.c"

        echo -e "\n\tPress Enter to continue..."
        read

        clear
        display_header "Compiling the current code: ${dir} ( using cc and all the flags :P )"
        cc -Wall -Wextra -Werror "${dir}count_and_say.c" -o "${dir}count_and_say"

        if [[ $? -ne 0 ]]; then
            print_error "Compilation failed for the code ${dir}"
            echo -e "\n\tPress Enter to continue..."
            read
            continue
        else
            print_success "Compilation successful for the code ${dir}"
        fi

        echo -e "\n\tPress Enter to continue..."
        read

        clear
        display_header "Take a look at the ${dir}\n"
        sleep 1

        cat "${dir}/count_and_say.c"

        echo -e "\n\tPress Enter to continue..."
        read

        clear
        display_header "Executing the ${dir} program with some arguments:"
        for arg in "${args[@]}"; do
            printf "\n./count_and_say.c %s\n" "$arg"
            printf "\nOutput:\n\n"
            ./"${dir}count_and_say" "$arg"
            printf "\n______________\n"
            sleep 1
        done
        printf "\nTesting with 2 arguments:\n\n"
        printf "\n./count_and_say.c %s\n" "abc 123"
        printf "\nOutput:\n\n"
        ./"${dir}count_and_say" "abc" "123"
        printf "\n______________\n"
        sleep 1
        printf "\nTesting with 0 arguments:\n\n"
        printf "\n./count_and_say.c %s\n"
        printf "\nOutput:\n\n"
        ./"${dir}count_and_say"
        printf "\n______________\n"
        sleep 1

        echo -e "\n\tPress Enter to continue..."
        read
    fi
done

clear
counter=1
display_header "Now lets make a quick recap, take a look into every code so you can pick better ;)"

for dir in */; do
    if [[ -f "${dir}/count_and_say.c" ]]; then
        display_header "Code #$counter from ${dir}count_and_say.c"
        cat "${dir}/count_and_say.c"
        echo -e "\n"
        ((counter++))
    fi
done

echo -e "\n\tPress Enter to continue..."
read

clear
for i in {1..3}; do
    while true; do
        display_header "What is the TOP#$i Code in your opinion? (write just the code number: e.g. 1)"
        read top_code

        if [[ -z "$top_code" || ! "$top_code" =~ ^[0-9]+$ || "$top_code" -lt 1 || "$top_code" -gt 11 ]]; then
            print_error "Invalid input! Please enter a number between 1 and 11."
        else
            echo -e "\tTOP#$i: Code #$top_code" >>"$output_file"
            break
        fi
    done
done
echo -e "\n\tPress Enter to continue..."
read

clear
display_header "Your votes are now saved in a file called $output_file in the root of this directory, if you want to change your vote, run this script again (or just edit the .txt lol)"
echo -e "\n\tPress Enter to continue..."
read

display_header "Your next and final step now is to send the $output_file in the Discord channel 'coding-challenge' until 13h42 of today"
echo -e "\n\tPress Enter to continue..."
read

clear
display_header "btw, do you have any feedback about the event? You can send it now! Just type it here (Or just press Enter if you don't want to provide feedback)"
read feedback
echo -e "\t==============================" >>"$output_file"
echo -e "\tFeedback: $feedback" >>"$output_file"

echo -e "\n\tNow, press Enter for the last time to end this program! Dont forget to send the file in Discord"
read

xdg-open .
