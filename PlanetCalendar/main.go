package main

/*
#include "4week.c"
#include "my_function.c"
#include "type.c"
#include "satis.c"
#include "cal_calculation.c"
#include "calendar.c"
*/
import "C"
import (
	"fmt"
	"html/template"
	"io/ioutil"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

type Page struct {
	Title string
	Body1 string
	Body2 string
	Body3 string
}

type ContactDetails struct {
	Gender1  string
	Year1    string
	Month1   string
	Day1     string
	Hours1   string
	Minutes1 string
	Tknow1   string
	Gender2  string
	Year2    string
	Month2   string
	Day2     string
	Hours2   string
	Minutes2 string
	Tknow2   string
}

/*
	func loadPage(wType string, mType string, satis string) (*Page, error) {
		body := "여자 Type\n"
		filename1 := wType + ".txt"
		temp1, err := ioutil.ReadFile(filename1)
		body += string(temp1[:])
		body += "\n남자 Type\n"
		filename2 := mType + ".txt"
		temp2, err := ioutil.ReadFile(filename2)
		body += string(temp2[:])
		body += "\n만족도 결과\n"
		filename3 := satis + ".txt"
		temp3, err := ioutil.ReadFile(filename3)
		body += string(temp3[:])
		if err != nil {
			return nil, err
		}
		print(body)
		return &Page{Title: "Result", Body: body}, nil
	}

	func renderTemplate(w http.ResponseWriter, p *Page) {
		t := template.Must(template.ParseFiles("result.html"))
		t.Execute(w, p)
	}

	func resultHandler(w http.ResponseWriter, r *http.Request) {
		var pR *Results

		pR = getResults(r)
		p, _ := loadPage(pR.wType, pR.mType, pR.Satis)
		renderTemplate(w, p)
	}

	func getResults(r *http.Request) *Results {
		var result string

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
		intTknow1, _ := strconv.ParseInt(details.Tknow1, 10, 64)
		intGender2, _ := strconv.ParseInt(details.Gender2, 10, 64)
		intYear2, _ := strconv.ParseInt(details.Year2, 10, 64)
		intMonth2, _ := strconv.ParseInt(details.Month2, 10, 64)
		intDay2, _ := strconv.ParseInt(details.Day2, 10, 64)
		intHours2, _ := strconv.ParseInt(details.Hours2, 10, 64)
		intMinutes2, _ := strconv.ParseInt(details.Minutes2, 10, 64)
		intTknow2, _ := strconv.ParseInt(details.Tknow1, 10, 64)
		fmt.Println(intGender1, intYear1, intMonth1, intDay1, intHours1, intMinutes1, intTknow1, intGender2, intYear2, intMonth2, intDay2, intHours2, intMinutes2, intTknow2)
		result = C.GoString(C._4week(C.int(intGender1), C.int(intYear1), C.int(intMonth1), C.int(intDay1), C.int(intHours1), C.int(intMinutes1), C.int(intTknow1), C.int(intGender2), C.int(intYear2), C.int(intMonth2), C.int(intDay2), C.int(intHours2), C.int(intMinutes2), C.int(intTknow2)))
		return &Results{
			wType: result[:2],
			mType: result[2:4],
			Satis: result[4:],
		}
	}
*/
func main() {
	r := mux.NewRouter()
	tmpl := template.Must(template.ParseFiles("index.html"))

	r.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		tmpl.Execute(w, nil)
	}).Methods("GET")

	r.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		var result string

		details := ContactDetails{
			//Gender1:  r.FormValue("Gender1"),
			Year1:    r.FormValue("Year1"),
			Month1:   r.FormValue("Month1"),
			Day1:     r.FormValue("Day1"),
			Hours1:   r.FormValue("Hours1"),
			Minutes1: r.FormValue("Minutes1"),
			//Tknow1:   r.FormValue("Tknow1"),
			//Gender2:  r.FormValue("Gender2"),
			Year2:    r.FormValue("Year2"),
			Month2:   r.FormValue("Month2"),
			Day2:     r.FormValue("Day2"),
			Hours2:   r.FormValue("Hours2"),
			Minutes2: r.FormValue("Minutes2"),
			//Tknow2:   r.FormValue("Tknow2"),
		}
		intGender1 := 0
		intYear1, _ := strconv.ParseInt(details.Year1, 10, 64)
		intMonth1, _ := strconv.ParseInt(details.Month1, 10, 64)
		intDay1, _ := strconv.ParseInt(details.Day1, 10, 64)
		intHours1, _ := strconv.ParseInt(details.Hours1, 10, 64)
		intMinutes1, _ := strconv.ParseInt(details.Minutes1, 10, 64)
		intTknow1 := 1
		intGender2 := 1
		intYear2, _ := strconv.ParseInt(details.Year2, 10, 64)
		intMonth2, _ := strconv.ParseInt(details.Month2, 10, 64)
		intDay2, _ := strconv.ParseInt(details.Day2, 10, 64)
		intHours2, _ := strconv.ParseInt(details.Hours2, 10, 64)
		intMinutes2, _ := strconv.ParseInt(details.Minutes2, 10, 64)
		intTknow2 := 1
		fmt.Println(intYear1, intMonth1, intDay1, intHours1, intMinutes1, intYear2, intMonth2, intDay2, intHours2, intMinutes2)
		result = C.GoString(C._4week(C.int(intGender1), C.int(intYear1), C.int(intMonth1), C.int(intDay1), C.int(intHours1), C.int(intMinutes1), C.int(intTknow1), C.int(intGender2), C.int(intYear2), C.int(intMonth2), C.int(intDay2), C.int(intHours2), C.int(intMinutes2), C.int(intTknow2)))

		typePath := "type/"
		satisPath := "satis/"
		fw := typePath + result[:2] + ".txt"
		fm := typePath + result[2:4] + ".txt"
		fs := satisPath + result[4:] + ".txt"

		temp1, _ := ioutil.ReadFile(fw)
		wtype := string(temp1[:])
		temp2, _ := ioutil.ReadFile(fm)
		mtype := string(temp2[:])
		temp3, _ := ioutil.ReadFile(fs)
		satis := string(temp3[:])

		page := Page{
			Title: "Result",
			Body1: wtype,
			Body2: mtype,
			Body3: satis,
		}
		t := template.Must(template.ParseFiles("result.html"))
		t.Execute(w, page)
	}).Methods("POST")
	http.ListenAndServe(":8080", r)
}
