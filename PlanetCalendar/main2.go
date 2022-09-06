package main

/*
#include "cal_calculation.c"
#include "calendar.c"
#include "4week.c"
#include "my_function.c"
#include "type.c"
#include "satis.c"
*/
import "C"
import (
	"fmt"
	"html/template"
	"net/http"
	"os"
	"strconv"

	"github.com/gorilla/mux"
)

type ContactDetails struct {
	Gender1  string
	Year1    string
	Month1   string
	Day1     string
	Hours1   string
	Minutes1 string
	Gender2  string
	Year2    string
	Month2   string
	Day2     string
	Hours2   string
	Minutes2 string
}

func main() {
	r := mux.NewRouter()
	tmpl := template.Must(template.ParseFiles("index2.html"))

	r.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		tmpl.Execute(w, nil)
	}).Methods("GET")

	r.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		details := ContactDetails{
			Gender1:  r.FormValue("Gender1"),
			Year1:    r.FormValue("Year1"),
			Month1:   r.FormValue("Month1"),
			Day1:     r.FormValue("Day1"),
			Hours1:   r.FormValue("Hours1"),
			Minutes1: r.FormValue("Minutes1"),
			Gender2:  r.FormValue("Gender2"),
			Year2:    r.FormValue("Year2"),
			Month2:   r.FormValue("Month2"),
			Day2:     r.FormValue("Day2"),
			Hours2:   r.FormValue("Hours2"),
			Minutes2: r.FormValue("Minutes2"),
		}
		intGender1, _ := strconv.ParseInt(details.Gender1, 10, 64)
		intYear1, _ := strconv.ParseInt(details.Year1, 10, 64)
		intMonth1, _ := strconv.ParseInt(details.Month1, 10, 64)
		intDay1, _ := strconv.ParseInt(details.Day1, 10, 64)
		intHours1, _ := strconv.ParseInt(details.Hours1, 10, 64)
		intMinutes1, _ := strconv.ParseInt(details.Minutes1, 10, 64)
		intGender2, _ := strconv.ParseInt(details.Gender2, 10, 64)
		intYear2, _ := strconv.ParseInt(details.Year2, 10, 64)
		intMonth2, _ := strconv.ParseInt(details.Month2, 10, 64)
		intDay2, _ := strconv.ParseInt(details.Day2, 10, 64)
		intHours2, _ := strconv.ParseInt(details.Hours2, 10, 64)
		intMinutes2, _ := strconv.ParseInt(details.Minutes2, 10, 64)

		fmt.Println(intGender1, intYear1, intMonth1, intDay1, intHours1, intMinutes1, intGender2, intYear2, intMonth2, intDay2, intHours2, intMinutes2)

		C._4week(C.int(intGender1), C.int(intYear1), C.int(intMonth1), C.int(intDay1), C.int(intHours1), C.int(intMinutes1), C.int(intGender2), C.int(intYear2), C.int(intMonth2), C.int(intDay2), C.int(intHours2), C.int(intMinutes2))

		filename1 := C.GoString(C.type_result1) + ".txt"
		fmt.Println(filename1)
		file1, _ := os.Open(filename1)
		buff1 := make([]byte, 1024)
		for {
			cnt, _ := file1.Read(buff1)
			if cnt == 0 {
				break
			}
			fmt.Fprintf(w, "%s", buff1[:cnt])
		}

		filename2 := C.GoString(C.type_result2) + ".txt"
		fmt.Println(filename2)
		file2, _ := os.Open(filename2)
		buff2 := make([]byte, 1024)
		for {
			cnt, _ := file2.Read(buff2)
			if cnt == 0 {
				break
			}
			fmt.Fprintf(w, "%s", buff2[:cnt])
		}
		//tmpl.Execute(w, struct{ Success bool }{true})

	}).Methods("POST")

	http.ListenAndServe(":8080", r)
}
